class Solution {
public:
    int numberOfPairs(vector<vector<int>>& v) {
        int n=v.size();
        int number_of_pair = 0;
        for(int i=0;i<n;i++) {
            int cx = v[i][0], cy = v[i][1];
            for(int j=0; j<n; j++) {
                if(i == j)
                    continue;
                int tx = v[j][0], ty = v[j][1];
                int flag = 0;
                if(cy >= ty && cx <= tx) {

                    for(int k=0; k<n; k++) {
                        if(k==i || k==j)
                            continue;
                        int kx = v[k][0], ky = v[k][1];
                        if(kx>=cx && kx<=tx && ky>=ty && ky<=cy) {
                            flag=1;
                            break;
                        }
                    }
                    if(flag == 0)
                        number_of_pair++;
                }
                
            }
        }
        return number_of_pair;
    }
};
