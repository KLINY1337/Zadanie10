#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

vector <int> prefix(string s){
	
	vector <int> pref_length(s.size(), 0);

	for (int i = 1; i < s.size(); i++) {
		int cur_len = pref_length[i - 1];
		//k++;
		while (cur_len > 0 && s[i] != s[cur_len])
		{
			/*k++;*/ cur_len = pref_length[cur_len - 1];
		}

		if (s[i] == s[cur_len]) {pref_length[i] = cur_len + 1;
	}
		else { pref_length[i] = cur_len; }
	}
	return pref_length;
}

int search(string text, string templ) {
	vector <int> prefix_vec = prefix(templ + "@" + text);

	for (int i = templ.size() + 1; i < prefix_vec.size(); i++) {
		//k++;
		if (prefix_vec[i] == templ.size()) return i - 2 * templ.size();
	}
	return -1;
}

bool IsValidPhone(string text) {
	const regex exp("[\+][7][\-][0-9]{3}[\-][0-9]{3}[\-][0-9]{2}[\-][0-9]{2}");

	return regex_match(text, exp);
}

int BMSearch(const char *string, const char *substring){
  int  sl, ssl;
  int res = -1;
  sl = strlen(string);
  ssl = strlen(substring);
  if ( sl == 0 ) 
    cout << "Неверно задана строка\n"; 
  else if ( ssl == 0 ) 
    cout << "Неверно задана подстрока\n"; 
  else {
    int  i, Pos;
    int  BMT[256];
    for ( i = 0; i < 256; i ++ )
      BMT[i] = ssl;
    for ( i = ssl-1; i >= 0; i-- )
      if ( BMT[(short)(substring[i])] == ssl ) 
        BMT[(short)(substring[i])] = ssl - i - 1;
    Pos = ssl - 1;
    while ( Pos < sl )
      if ( substring[ssl - 1] != string[Pos] )
        Pos = Pos + BMT[(short)(string[Pos])];
      else 
        for ( i = ssl - 2; i >= 0; i-- ){
          if ( substring[i] != string[Pos - ssl + i + 1] ) {
            Pos += BMT[(short)(string[Pos - ssl + i + 1])] - 1;
            break;
          }
          else
            if ( i == 0 )
              return Pos - ssl + 1;
          cout << "\t" << i << endl;
        }
  }
  return res;
}