//
// Created by mateo on 5/09/2024.
//

vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> results;
    int contador = 0;
    while (contador < nums.size()){
        int valor = nums[contador];
        for (int j = 0; j < valor; ++j) {
            results.push_back(nums[contador+1]);
        }
        contador += 2;
    }
    return results;
}