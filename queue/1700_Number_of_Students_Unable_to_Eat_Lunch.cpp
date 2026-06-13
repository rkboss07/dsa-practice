class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        queue<int> sand;

        for (int i = 0; i < students.size(); i++){
            stu.push(students[i]);
            sand.push(sandwiches[i]);
        }
        int counter = 0;
        while (counter!=stu.size()){
            if (stu.front() == sand.front()) {
                counter = 0;
                stu.pop();
                sand.pop();
            }
            else {
                stu.push(stu.front());
                stu.pop();
                counter++;
            }
        }
        return counter;

        
    }
};