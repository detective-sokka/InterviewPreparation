#include <limits>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Twitter {
    struct User {
        int userId;
        set<int> following;
        User (int userId) : userId {userId} {
            following.insert(userId);
        }
    };
    
    struct Tweet {
        int tweetId;
        int userId;
        size_t stamp;
        Tweet (int tweetId, int userId) : tweetId {tweetId},
                                          userId {userId},
                                          stamp {counter++} {
        }
    };

    struct CompareUsersById {
        bool operator() (const User& user1, const User& user2) const {
            return user1.userId < user2.userId;
        }
    };

    struct CompareTweetByStamp {
        bool operator() (const Tweet& tweet1, const Tweet& tweet2) const {
            return tweet1.stamp > tweet2.stamp;
        }
    };

    inline static size_t counter = 0;
    unordered_map<int, User> mUsers;
    unordered_map<int, vector<Tweet>> mUserTweets;

public:
    Twitter() : mUsers{},
                mUserTweets {} {
    }
    
    void postTweet(int userId, int tweetId) {
        if (mUserTweets.find(userId) == mUserTweets.end())
            mUserTweets[userId] = User(userId);
        Tweet tweet(userId, tweetId);
        mUserTweets[userId].emplace_back(tweet);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<Tweet, vector<Tweet>, CompareTweetByStamp> followerTweets(CompareTweetByStamp{}); 

        for (const auto& follower : mUsers[userId].following) 
            for (const auto& tweet : mUserTweets[follower])
                followerTweets.push(tweet);
        
        while (result.size() < 10 && !followerTweets.empty()) {
            result.emplace_back(followerTweets.top().tweetId);
            followerTweets.pop();
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        mUsers[followerId].following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mUsers[followerId].following.erase(followeeId);
    }
};