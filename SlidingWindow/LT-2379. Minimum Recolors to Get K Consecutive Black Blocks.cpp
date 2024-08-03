class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int countw=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W'){
                countw++;
            }
        }
        int r=k; //keeping the window size as K and checking which window has min 'w' 
        int minlen=countw;
        int l=1;
        while(r<blocks.size()){
            int i=l;
            countw=0;
            cout<<minlen<<endl;
            while(i<=r){
                if(blocks[i]=='W'){
                    countw++;
                }
                i++;
            }
            if(countw<minlen){
                minlen=countw;
            }
            l++;
            r++;
        }
        return minlen;
    }
};
