class Robot {
public:
    int w, h;
    int x, y;
    int dir; 

    vector<string> dname = {"East","North","West","South"};
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int cycle;

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        cycle = 2 * (w + h - 2);
    }
    
    void step(int num) {
        if(cycle == 0) return;

        num = num % cycle;

        if(num == 0) num = cycle;

        while(num--) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4; 
                nx = x + dx[dir];
                ny = y + dy[dir];
            }

            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dname[dir];
    }
};