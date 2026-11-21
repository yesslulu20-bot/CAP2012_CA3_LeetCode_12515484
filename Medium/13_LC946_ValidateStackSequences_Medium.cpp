
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        stack<int> st;
        int j = 0;

        for (int i = 0; i < pushed.size(); i++) {

            // Push the current element
            st.push(pushed[i]);

            // Check whether the stack top matches popped[j]
            while (!st.empty() && st.top() == popped[j]) {

                // Remove the top element
                st.pop();

                // Move to the next popped element
                j++;
            }
        }

        // Check if all elements were popped
        return j==popped.size();
    }
};
