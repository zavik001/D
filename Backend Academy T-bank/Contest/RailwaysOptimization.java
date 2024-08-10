import java.util.*;

public class RailwaysOptimization {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int trackLength = scanner.nextInt();
        int numberOfTracks = scanner.nextInt();
        int[] startPositions = new int[numberOfTracks];
        int[] endPositions = new int[numberOfTracks];
        
        for (int i = 0; i < numberOfTracks; ++i) {
            startPositions[i] = scanner.nextInt();
            endPositions[i] = scanner.nextInt();
        }
        
        scanner.close();
        
        RailwaysOptimization railways = new RailwaysOptimization();
        int result = railways.minimizeActions(trackLength, numberOfTracks, startPositions, endPositions);
        System.out.println(result);
    }

    public int minimizeActions(int trackLength, int numberOfTracks, int[] startPositions, int[] endPositions) {
        int[] previousDp = new int[trackLength + 1];
        int[] currentDp = new int[trackLength + 1];

        initializeDpArray(previousDp, startPositions[0], endPositions[0], trackLength);

        for (int i = 1; i < numberOfTracks; ++i) {
            int minValue = Integer.MAX_VALUE;
            Deque<Integer> deque = new ArrayDeque<>();

            minValue = processTrackSegment(startPositions[i], endPositions[i], trackLength, previousDp, currentDp, minValue, deque);

            previousDp = Arrays.copyOf(currentDp, currentDp.length);
            Arrays.fill(currentDp, 0);
        }

        return findMinimumValue(previousDp, trackLength);
    }

    private void initializeDpArray(int[] dpArray, int start, int end, int length) {
        for (int i = start - 1; i >= 1; --i) {
            dpArray[i] = start - i;
        }
        for (int i = end + 1; i <= length; ++i) {
            dpArray[i] = i - end;
        }
    }

    private int processTrackSegment(int start, int end, int length, int[] previousDp, int[] currentDp, int minValue, Deque<Integer> deque) {
        for (int j = start; j <= end; ++j) {
            minValue = Math.min(minValue, previousDp[j]);
            while (!deque.isEmpty() && previousDp[deque.getLast()] > previousDp[j]) {
                deque.removeLast();
            }
            deque.addLast(j);
        }

        int segmentLength = end - start + 1;
        for (int j = end + 1; j <= length; ++j) {
            while (!deque.isEmpty() && deque.getFirst() <= j - segmentLength) {
                deque.removeFirst();
            }
            while (!deque.isEmpty() && previousDp[deque.getLast()] > previousDp[j]) {
                deque.removeLast();
            }
            deque.addLast(j);
            currentDp[j] = j - end + previousDp[deque.getFirst()];
        }

        deque.clear();
        for (int j = end; j >= start; --j) {
            while (!deque.isEmpty() && previousDp[deque.getLast()] > previousDp[j]) {
                deque.removeLast();
            }
            deque.addLast(j);
        }

        for (int j = start - 1; j >= 1; --j) {
            while (!deque.isEmpty() && deque.getFirst() >= j + segmentLength) {
                deque.removeFirst();
            }
            while (!deque.isEmpty() && previousDp[deque.getLast()] > previousDp[j]) {
                deque.removeLast();
            }
            deque.addLast(j);
            currentDp[j] = start - j + previousDp[deque.getFirst()];
        }

        for (int j = start; j <= end; ++j) {
            currentDp[j] = minValue;
        }
        return minValue;
    }

    private int findMinimumValue(int[] dpArray, int length) {
        int minValue = Integer.MAX_VALUE;
        for (int i = 1; i <= length; ++i) {
            minValue = Math.min(minValue, dpArray[i]);
        }
        return minValue;
    }
}