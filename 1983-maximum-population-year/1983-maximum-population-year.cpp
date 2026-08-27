class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> population(101, 0);

        for (auto& person : logs) {
            int birth = person[0];
            int death = person[1];

            population[birth - 1950]++;
            population[death - 1950]--;
        }

        int maxPopulation = 0;
        int answer = 1950;
        int currentPopulation = 0;

        for (int i = 0; i <= 100; i++) {
            currentPopulation += population[i];

            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                answer = 1950 + i;
            }
        }

        return answer;
    }
};