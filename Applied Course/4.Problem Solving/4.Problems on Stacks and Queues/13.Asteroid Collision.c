

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define abs(a) ((a) > 0 ? (a) : (-a))

int stack[10001];
int top;

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    memset(stack, 0, sizeof(stack));
    top = 0;
    
    for(int i = 0; i < asteroidsSize; i++)
    {
        int num = asteroids[i];
        if(top == 0 || !(num < 0 && stack[top - 1] > 0))
            stack[top++] = num;
        else
        {
            while(top > 0 && (stack[top - 1] > 0 && num < 0) && abs(stack[top - 1]) < abs(num))    
                stack[--top] = 0;              
            
            if(top == 0 || stack[top - 1] < 0)
                stack[top++] = num;
            else if(top > 0 && stack[top - 1] == abs(num))
                stack[--top] = 0;
        }
    }
    
    *returnSize = top;
    return stack;
}
