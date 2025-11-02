# I-C-YOU

#### Repository for all the C codes related to graphics and a summarization of all the other repositories branching from this :) 

##### Basic information about all the algorithms:

##### 1. DDA - Digital Differential Analyzer 
The steps involved in DDA line generation algorithm are:
1. Input the two endpoints of the line segment, (x1,y1) and (x2,y2).
2. Calculate the difference between the x-coordinates and y-coordinates of the endpoints as dx and dy respectively.
3. Calculate the slope of the line as m = dy/dx.
4. Set the initial point of the line as (x1,y1).
5. Loop through the x-coordinates of the line, incrementing by one each time, and calculate the corresponding y-coordinate using the equation y = y1 + m(x - x1).
6. Plot the pixel at the calculated (x,y) coordinate.
7. Repeat steps 5 and 6 until the endpoint (x2,y2) is reached.
8. Sample i/p: 100 200 250 200
##### 2. Bresenham's Line Drawing Algorithm
The steps involved in Bresenhams line generation algorithm are:
1. The steps involved in DDA line generation algorithm are:
2. Input the two endpoints of the line. Save the left endpoint as (x0, y0).
3. Plot the first point (x0, y0).
4. Calculate the constants Δx, Δy, 2Δy, and (2Δy - 2Δx).
5. Calculate the initial decision parameter: p0 = 2Δy - Δx
6. For each xk along the line, starting with k = 0:
    1. If pk < 0, plot (xk+1, yk) and set pk + 1 = pk + 2Δy
    2. Otherwise, plot (xk+1, yk+1) and set pk+1 = pk + 2Δy - 2Δx
7. Repeat step 5 until you reach the end point.
8. Sample i/p: 100 100 250 200
##### 3. Midpoint Circle Drawing Algorithm
The algorithm follows these steps −
- **Start with an initial point** − The first point to be plotted is (r, 0), which lies on the positive X-axis.
- **Calculate the initial decision parameter** − The initial decision parameter is computed as 
P1=1−r
1. **Iterate through points in the first octant** − For each subsequent point, we check whether the next pixel is above or below the circle or not. The next pixel is either at (x,y+1) or (x−1,y+1)
    1. If the decision parameter is less than or equal to zero, the midpoint is inside the circle. In this case, the next pixel is (x,y+1).
    2. If the decision parameter is greater than zero, the midpoint is outside the circle. The next pixel is (x−1,y+1).
2. **Update the decision parameter** − For each new pixel, update the decision parameter depending on which pixel was chosen.
    1. If the midpoint was inside or on the circle −    
    2. Pk+1=Pk+2yk+1
    3. If the midpoint was outside the circle −
    4. Pk+1=Pk+2yk−2xk+1
3. Sample i/p: 200 200 50