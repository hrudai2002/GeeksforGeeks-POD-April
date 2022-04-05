https://practice.geeksforgeeks.org/problems/3f48d387900a38bd9fd0594b93f9f4f97f5ada8a1644/1


int countSquare(int n)
{
	    if(n <= 3)
	       return 0;
	    
	    int x = n/2 - 1;
	    return (x*(x + 1))/2;
}
