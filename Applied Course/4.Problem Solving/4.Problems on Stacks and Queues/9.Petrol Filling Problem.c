#include <stdio.h>
#include <stdlib.h>
 
struct PetrolPumpData
{
  int petrol;
  int distance;
};

/*It returns -1 if there is no possible tour*/
int getStartPointOfTour(struct PetrolPumpData arr[], int n)
{
    int start_point = 0;
    int end_point =  1;

    int curr_petrol = arr[start_point].petrol - arr[start_point].distance;

    while (end_point != start_point || curr_petrol < 0)
    {
        /*If the curr_petrol becomes less than zero then remove the starting point of the pump tour*/
        while (curr_petrol < 0 && start_point != end_point)
        {
            curr_petrol = curr_petrol - (arr[start_point].petrol - arr[start_point].distance);
            start_point = (start_point + 1)%n;
            if (start_point == 0)
               return -1;
        }
        /*Add petrol pump data to current petrol*/
        curr_petrol = curr_petrol + arr[end_point].petrol - arr[end_point].distance;
        end_point = (end_point + 1)%n;
    }
    return start_point;
}
 
int main()
{
    struct PetrolPumpData arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    int result = getStartPointOfTour(arr,4);
    if(result == -1)
    printf("No Possible tour\n");
    else
    printf("start point of the tour is %d\n", result);
    return 0;
}
