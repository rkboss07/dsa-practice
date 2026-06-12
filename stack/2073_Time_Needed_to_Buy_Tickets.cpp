class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
      queue<int> q1;
      for (int i=0; i< tickets.size(); i++) q1.push(i);
      int time = 0;
      while (!q1.empty()){
        time++;
        int front = q1.front();
        q1.pop();
        tickets[front]--;
        if (k== front && tickets[front] == 0) return time;
        if (tickets[front] != 0) q1.push(front);
      }
      return time;  
    }
};