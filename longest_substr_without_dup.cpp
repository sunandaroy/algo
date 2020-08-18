using namespace std;
// longest substring without duplication
// Time complexity = O(n)
// Space Complexity = O(d) where d = maximum number of unique letters present in the string, which is maximum 26
string longestSubstringWithoutDuplication(string str) {
	unordered_map<char, int> um;
	int longestString[2];
	longestString[0] = 0; //start index of longest string
	longestString[1] = 0; //end index of longest string
	int st_index = 0;
	int last_index;
	int i = 0;
	while(i < str.length()){
		if(um.find(str[i]) != um.end() && um[str[i]] >= st_index){
			last_index = i - 1;
			cout << "\n last index is:" << last_index;
			if( last_index - st_index > longestString[1] - longestString[0]){
				longestString[0] = st_index;
				longestString[1] = last_index;
			}
			st_index = um[str[i]] + 1;
			cout << "start index is:" << st_index;
		}
		um[str[i]] = i;
		i++;
	}
	last_index = i -1;
	if(last_index - st_index > longestString[1] - longestString[0]){
		longestString[0] = st_index;
		longestString[1] = last_index;
	}
  return str.substr(longestString[0], longestString[1] - longestString[0] +1);
}

