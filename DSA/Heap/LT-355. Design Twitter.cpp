class Twitter {
public:
    int timer;
    unordered_map<int,vector<pair<int,int>>> tweetmap; //userID:[timer,tweetIds]
    unordered_map<int,set<int>> followmap; //userID: [follweeIDs]
    Twitter() {
        timer=0;
    }
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({timer,tweetId});
        timer++;
    }
    vector<int> getNewsFeed(int userId) {
        vector<int> topTweets;
        followmap[userId].insert(userId);  //the user Himself is an follower to show his post
        using T = tuple<int, int, int, int>; // (time, tweetId, userId, index)
        priority_queue<T> pq;
         for (int followeeId : followmap[userId]) {
            if (!tweetmap[followeeId].empty()) {
                int idx = tweetmap[followeeId].size() - 1;
                auto [time, tweet] = tweetmap[followeeId][idx];
                pq.push({time, tweet, followeeId, idx - 1}); // use -time to simulate max-heap
            }
        }
        while (!pq.empty() && topTweets.size() < 10) {
            auto [time, tweet, uid, idx] = pq.top();
            pq.pop();
            topTweets.push_back(tweet);

            if (idx >= 0) {
                auto [ntime, ntweet] = tweetmap[uid][idx];
                pq.push({ntime, ntweet, uid, idx - 1});
            }
        }
        return topTweets;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followmap[followerId].find(followeeId)!=followmap[followerId].end()){
            followmap[followerId].erase(followeeId);
        }
    }
};
