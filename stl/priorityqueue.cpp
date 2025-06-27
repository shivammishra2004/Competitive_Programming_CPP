class Solution {
public:
    // Compute profit gain when adding a student to a class
    double computeGain(int pass, int total) {
        return (pass + 1.0) / (total + 1.0) - (pass * 1.0) / total;
    }
    template <typename T, typename Container, typename Compare>
void display_priority_queue(priority_queue<T, Container, Compare> pq) {
    cout << "Priority Queue: ";
    while (!pq.empty()) {
        cout << pq.top().first << "," << pq.top().second << " "; // Explicitly print pair members
        pq.pop();
    }
    cout << endl;
}


    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Custom comparator for priority queue
        auto comparator = [&](const pair<int, pair<int, int>>& a, 
                               const pair<int, pair<int, int>>& b) {
            // Compute gain for both classes and compare
            double gain1 = computeGain(a.second.first, a.second.second);
            double gain2 = computeGain(b.second.first, b.second.second);
            return gain1 < gain2;  // Reverse comparison for max-heap
        };

        // Priority queue to track classes with maximum potential gain
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       decltype(comparator)> pq(comparator);

        // Initialize priority queue with class indices and pass/total
        for (int i = 0; i < classes.size(); i++) {
            pq.push({i, {classes[i][0], classes[i][1]}});
        }


        // Distribute extra students
        for (int i = 0; i < extraStudents; i++) {
            // Get class with maximum gain
            auto top = pq.top();
            pq.pop();

            // Add a student to this class
            top.second.first++;   // Increment pass count
            top.second.second++;  // Increment total count

            // Push back to priority queue
            pq.push(top);
        }

        // Calculate final average
        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            totalRatio += (double)top.second.first / top.second.second;
        }

        return totalRatio / classes.size();
    }
};
\





*/ Basically if we use priority_queue we have to use an object as a comparator, if we use make_heap, we have to use a function as comparator


there is no top in make_heap