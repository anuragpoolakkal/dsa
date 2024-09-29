  // https://www.geeksforgeeks.org/problems/sorting-employees5907
  
  class Solution {
  public:
    vector<string> sortRecords(vector<string>& employee, vector<int>& salary) {
        vector<pair<string, int>> employeeSalary;
        
        for (int i = 0; i < employee.size(); i++) {
            employeeSalary.push_back({employee[i], salary[i]});
        }
        
        sort(employeeSalary.begin(), employeeSalary.end(), [](pair<string, int>& a, pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        
        vector<string> sortedEmployees;
            
        for (auto& emp : employeeSalary) {
            sortedEmployees.push_back(emp.first);
        }
        
        return sortedEmployees;
    };
};
