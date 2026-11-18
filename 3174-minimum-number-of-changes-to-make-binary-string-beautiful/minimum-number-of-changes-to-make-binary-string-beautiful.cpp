class Solution {
public:
    int minChanges(string s) {
        int n =s.size();
        char ch = s[0];
        int cnt=0;
        int changes=0;

        for(int i=0;i<n;i++){
            //Same as Prev Char then just increment Count
            if(s[i] == ch){
               cnt++;
               continue;
            }
            //Diff then prev Char
            //Suppose "001",where cnt of 0 -> 2
            if(cnt%2 == 0){
                //reset cnt to 1,for current character as for previous cnt we need not have to do changes 
                cnt=1;
            }else{
                //0001,in this case change 1 to 0.
                changes+=1;
                cnt=0;
            }
            ch=s[i];

        }
        return changes;
    }
};