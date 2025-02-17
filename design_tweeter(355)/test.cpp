#include<bits/stdc++.h>
using namespace std;

class Twitter {
    public:
        unordered_map<int,vector<pair<int,int>>> tweets; 
    /*  tweet ke saath time daalna padega kyoki top 10 recent tweet return karne hai
    [
    user1->[[time,tweetId],[time,tweetId]],     
    user1->[[time,tweetId],[time,tweetId]],
    ]
    */
        unordered_map<int,unordered_set<int>> followMap;
    /*  Each item in the news feed must be posted by users who the user followed 
    [
        follower1->[followee,followee...]  follower kisko-2 follow karta hai
        follower2->[followee,followee...] 
    ]
    */
        int count;   //time ke liye
        Twitter() {
            count=0;
        }
        
        void postTweet(int userId, int tweetId) {
            tweets[userId].push_back({count++,tweetId});
        }
        
        vector<int> getNewsFeed(int userId) {
            priority_queue<pair<int, int>> maxHeap;  //made a maxheap and put users and following tweets in it and at last just get the top 10 tweets from it
            
            // user tweets
            for (auto &t : tweets[userId]) {
                maxHeap.push(t);
            }
            
            // tweets of persons whom user is following
            for (int followee : followMap[userId]) {
                for (auto &t : tweets[followee]) {
                    maxHeap.push(t);
                }
            }
    
            // get top 10 tweets
            vector<int> result;
            for (int i = 0; i < 10 && !maxHeap.empty(); i++) {
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
            
            return result;     
        }
        
        void follow(int followerId, int followeeId) {
            followMap[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            followMap[followerId].erase(followeeId);  //followMap se particular followee ko delete kar paaye bina traverse kiye less complexity ke saath isliye unordered_set ka use kiya tha. erase ke use se specific person ko bina find kiye hum delete kar sakte hai seedhe. 
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