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

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, numWhites = 0, numRecolors = INT_MAX;

        for (int right = 0; right < blocks.size(); right++) {
            if (blocks[right] == 'W') {
                numWhites++;
            }

            if (right - left + 1 == k) {  //window size
                numRecolors = min(numRecolors, numWhites);

                if (blocks[left] == 'W') numWhites--;  //once the window moves

                left++;
            }
        }
        return numRecolors;
    }
};
