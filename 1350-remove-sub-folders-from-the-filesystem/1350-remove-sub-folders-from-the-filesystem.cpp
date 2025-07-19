class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;

        for (const string& f : folder){
            if (ans.empty() || f.find(ans.back() + "/") != 0){
                ans.push_back(f);
            }
        }
        return ans;
    }
};