

class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> followed;
    int time = 0;
    Twitter() {
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for (auto c : followed[userId]) {
            for (auto s : tweets[c]) {
                pq.push(s);
            }
        }
        for (auto c : tweets[userId]) {
            pq.push(c);
        }
        vector<int> tweet;
        for (int i = 0; i < 10; i++) {
            if (pq.empty()) break;
            tweet.push_back(pq.top().second);
            pq.pop();
        }
        return tweet;
    }

    void follow(int followerId, int followeeId) {
        followed[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followed[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */