https://practice.geeksforgeeks.org/problems/moving-on-grid1135/1


string movOnGrid(int r, int c) {
        swap(r, c);
        r = (r - 1) % 4;
        c = (c - 1) % 7;
        
        return (r != c) ? "JON" : "ARYA";
    }
