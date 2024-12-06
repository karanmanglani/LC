class Solution {
public:
    void helper(vector<vector<int>>& image,int m,int n, int i , int j, int col,int clr, vector<vector<bool>>& vis){
        if(i < 0 or i >= m or j < 0 or j >= n or vis[i][j] or image[i][j] != clr) return ;
        vis[i][j] = true;
        image[i][j] = col;
        helper(image,m,n,i-1,j,col,clr,vis); // up
        helper(image,m,n,i+1,j,col,clr,vis); // Down
        helper(image,m,n,i,j-1,col,clr,vis); // Left
        helper(image,m,n,i,j+1,col,clr,vis); // Right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int clr = image[sr][sc];
        helper(image,m,n,sr,sc,color,clr,vis);
        return image;
    }
};