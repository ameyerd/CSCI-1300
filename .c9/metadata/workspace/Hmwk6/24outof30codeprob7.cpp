{"filter":false,"title":"24outof30codeprob7.cpp","tooltip":"/Hmwk6/24outof30codeprob7.cpp","undoManager":{"mark":0,"position":0,"stack":[[{"start":{"row":0,"column":0},"end":{"row":91,"column":1},"action":"insert","lines":["// split","int split(string str, char c, string array[], int num) {","    ","    if (str.length() == 0) {","        return 0;","    }","    int a = 0;","    string word = \"\";","    int j = 0;","    str = str + c;","    for (int i = 0; i < str.length(); i++)","    {","        if (str[i] == c) ","        {","        \tif (word.length() == 0) continue;","        \tarray[a] = word; ","        \ta++;","            j++;","            word = \"\";","        } else {","            word = word + str[i];","        }","    }","    return j ;","    ","}","","","// read ratings","int readRatings(string fileName, string users[], int ratings[10][50], int numUsers, int maxRows, int maxColumns) {","    ","    ifstream fp;","    fp.open(fileName);","    ","    if (numUsers == maxRows) {","        return -2;","    }","    ","    ","    if (fp.is_open()) {","    ","        ","        // stores username in user array","        int i = numUsers;","        string s;","        string temp_array[maxColumns];","        ","        while (getline(fp, s)) {","            ","            // ratings","            ","            int m = 0;","        ","            for(int j = 1; j < split(s, ',' , temp_array, maxColumns); j++) {","                if (j < maxRows) {","                    string r = temp_array[j];","                ","                    int rat = stoi(r);","     ","                    ratings[i][m] = rat;","                    m++;","                    ","                    r = \"\";","                }","                else {","                    break;","                }","            ","            }","        ","            ","            // users","            split(s, ',', temp_array, maxColumns);","            ","            string user = temp_array[0];","            users[i] = user;","            i++;","            ","            ","        ","        }","        ","        ","     fp.close();","     return i;","     ","    }","      ","     else {","        return -1;","        }  ","}"],"id":1}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":8,"column":14},"end":{"row":8,"column":14},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1551518717657,"hash":"0d9d78eeb699f25319b116406dfa6479139cab04"}