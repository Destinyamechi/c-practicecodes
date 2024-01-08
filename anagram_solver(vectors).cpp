#include <iostream>
#include <string>
#include <algorithm>       
#include <vector>

using namespace std;

vector<vector<string>> getSearchResults(string arr[4],string query[2]){

    //intialize 2d vector and a normal 1d vector
    vector<vector<string>>vector2d;
    vector<string> stringVector;
    for(int i= 0; i<2; i++){
        for(int j= 0; j<4; j++){

            // check to see if the length of the words are equal then
            if(query[i].length()==arr[j].length()){

                //assign the origial words to a variables
                string original_arr_word = arr[j];
                //string original_query_word = query[i];

                // assign the words to variables and sort them, thenn compare if they are equal                
                string arr_word = arr[j];
                string query_word = query[i];

                //sort using the sort function and compare
                sort(arr_word.begin(),arr_word.end());
                sort(query_word.begin(),query_word.end());
                if(arr_word==query_word){

                    //push back the origianl word to the vector
                    stringVector.push_back(original_arr_word);
                }

            }
        }
        //add to the 2-dimensional vector
        vector2d.push_back(stringVector);

        // clear the vector so it would accept for the other elements in query array
        stringVector.clear();

    }
    return vector2d;
}

int main(){
    string words[4]= {"duel","speed","dule","cars"};
    string queries [2] = {"spede","deul"};
    vector<vector<string>>red = getSearchResults(words,queries);
    for(const auto& row: red){
        for(const auto& element:row){
            cout<<element<<" "<<endl;
        }
    }

    return 0;

}