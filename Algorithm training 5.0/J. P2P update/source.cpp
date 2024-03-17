#include <limits>
#include <vector>
#include <fstream>

using namespace std;

class Device {
public:
   Device(long long k, long long n) {
      updates = vector<bool>(k, false);
      valueble = vector<long long>(n, 0);
      requests = vector<Device*>();
      countPartOfUpdates = 0;
      nowNeedpartOfUpdate = -1;
      iters = 0;
      indexInDevices = devices.size();
      myRequestOK = false;
      idDeviceRequest = -1;
      devices.push_back(this);
   }

   void choose_part_of_update() {
      nowNeedpartOfUpdate = -1;
      long long minCountUpdates = std::numeric_limits<long long>::max();
      for (size_t i = 0; i < updates.size(); ++i) {
         if (updates[i] == false && commonUpdates[i] < minCountUpdates) {
               minCountUpdates = commonUpdates[i];
               nowNeedpartOfUpdate = i;
         }
      }
      if (nowNeedpartOfUpdate != -1) {
         ++iters;
      }
   }

   void choose_device_who_have_part_of_update() {
      if (nowNeedpartOfUpdate == -1) {
         return;
      }
      long long minDownloadUpdates = std::numeric_limits<long long>::max();
      Device* deviceRequest = nullptr;
      for (size_t i = 0; i < devices.size(); ++i) {
         Device* dev = devices[i];
         if (dev->updates[nowNeedpartOfUpdate] == true) {
               if (dev->countPartOfUpdates < minDownloadUpdates) {
                  deviceRequest = dev;
                  minDownloadUpdates = dev->countPartOfUpdates;
               }
         }
      }
      if (deviceRequest != nullptr) {
         deviceRequest->requests.push_back(this);
      }
   }

   void choose_request() {
      long long minCountPartOfUpdates = std::numeric_limits<long long>::max();
      long long iOkDevice = -1;
      long long maxValueble = -1;
      for (size_t i = 0; i < this->requests.size(); ++i) {
         Device* dev = requests[i];
         if (valueble[dev->indexInDevices] > maxValueble) {
               iOkDevice = dev->indexInDevices;
               minCountPartOfUpdates = dev->countPartOfUpdates;
               maxValueble = valueble[dev->indexInDevices];
         }
         else if (valueble[dev->indexInDevices] == maxValueble) {
               if (minCountPartOfUpdates > dev->countPartOfUpdates) {
                  iOkDevice = dev->indexInDevices;
                  minCountPartOfUpdates = dev->countPartOfUpdates;
               }
         }
      }
      this->requests.clear();
      if (iOkDevice != -1) {
         Device* dev = devices[iOkDevice];
         dev->myRequestOK = true;
         dev->idDeviceRequest = this->indexInDevices;
      }
   }

   void request_OK() {
      if (!myRequestOK)
         return;
      ++countPartOfUpdates;
      updates[nowNeedpartOfUpdate] = true;
      ++commonUpdates[nowNeedpartOfUpdate];
      ++valueble[idDeviceRequest];
      myRequestOK = false;
   }

   static vector<Device*> devices;
   static vector<long long> commonUpdates;
   vector<bool> updates;
   vector<long long> valueble;
   vector<Device*> requests;
   bool myRequestOK;
   int idDeviceRequest;
   long long countPartOfUpdates;
   long long nowNeedpartOfUpdate;
   long long iters;
   long long indexInDevices;
};

vector<Device*> Device::devices;
vector<long long> Device::commonUpdates;


vector<long long> decide(long long n, long long k) {
   Device::devices = vector<Device*>();
   Device::commonUpdates = vector<long long>(k, 1);
   for (long long i = 0; i < n; ++i) {
      Device* dev = new Device(k, n);
   }
   Device::devices[0]->countPartOfUpdates = k;
   Device::devices[0]->updates = vector<bool>(k, true);
   while (true) {
      long long thisIsEnd = 0;
      for (Device* dev : Device::devices) {
         if (dev->countPartOfUpdates == k) {
               thisIsEnd += 1;
               continue;
         }
         dev->choose_part_of_update();
      }
      if (thisIsEnd == n) {
         break;
      }

      for (Device* dev : Device::devices) {
         if (dev->countPartOfUpdates == k)
               continue;
         dev->choose_device_who_have_part_of_update();
      }
      for (Device* dev : Device::devices) {
         if (dev->requests.size() == 0)
               continue;
         dev->choose_request();
      }
      for (Device* dev : Device::devices) {
         if (dev->myRequestOK == false) {
               continue;
         }
         dev->request_OK();
      }
   }

   vector<long long> ans;
   for (Device* dev : Device::devices) {
      ans.push_back(dev->iters);
   }
   for (Device* dev : Device::devices) {
      delete dev;
   }
   return ans;
}


int main() {
   ifstream iFile("input.txt");
   long long n, k;
   iFile >> n >> k;

   vector<long long> v = decide(n, k);
   ofstream outputFile("output.txt");
   for (size_t i = 1; i < v.size(); ++i) {
      outputFile << v[i] << " ";
   }

   return 0;
}