class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;

        for (string email : emails) {
            string local = "";
            string domain = "";

            int i = 0;
            while (email[i] != '@') {
                if (email[i] == '+') {
                    while (email[i] != '@') {
                        i++;
                    }
                    break;
                }

                if (email[i] != '.') {
                    local += email[i];
                }

                i++;
            }
            domain = email.substr(i + 1);

            uniqueEmails.insert(local + "@" + domain);
        }

        return uniqueEmails.size();
    }
};