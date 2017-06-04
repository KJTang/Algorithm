// solution: 49ms, 23 cases
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets_.push_back(std::make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        std::vector<int> feed;
        auto& followees = followees_[userId];
        for (auto tweet = tweets_.rbegin(); tweet != tweets_.rend() && feed.size() != 10; ++tweet) {
            if (tweet->first == userId) {
                feed.push_back(tweet->second);
            } else {
                auto it = followees.find(tweet->first);
                if (it != followees.end()) {
                    feed.push_back(tweet->second);
                }
            }
        }
        return feed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        auto& followees = followees_[followerId];
        auto it = followees.find(followeeId);
        if (it == followees.end()) {
            followees.insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto& followees = followees_[followerId];
        auto it = followees.find(followeeId);
        if (it != followees.end()) {
            followees.erase(it);
        }
    }
private:
    std::map<int, std::set<int>> followees_;
    std::vector<std::pair<int, int>> tweets_;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */