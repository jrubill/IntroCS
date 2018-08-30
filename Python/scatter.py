import matplotlib.pyplot as plt 
import numpy as np

# reference: https://stackoverflow.com/questions/22239691/code-for-line-of-best-fit-of-a-scatter-plot-in-python

def run():
    x = list()
    y = list()
    
    # Get our x and y values from the CSV
    with open("data.csv") as f:
        for line in f:
            data = line.split(',')
            x.append(float(data[0]))
            y.append(float(data[1]))
    
    # Sort them by their X values in case some tomfoolery occurred
    sortVals = sorted(range(len(x)), key=lambda i: x[i])
    x = [x[i] for i in sortVals]
    y = [y[i] for i in sortVals]
    
    # Put them values on the graph
    plt.scatter(x,y)


    # X and Y values, linear fit
    bestFit = np.polyfit(x,y,1, full=True)
    slope = bestFit[0][0]
    intercept = bestFit[0][1]

    x1 = [min(x), max(x)] # Generate all of our x values from x0 to xn
    y1 = [slope*xx + intercept for xx in x1]
    '''
    The above step is just plotting our line of best fit
    x1 is our x axis,
    y1 is our y axis.
    y = mx + b
    or
    y1 = slope*(x)+ intercept
    '''

    # This is our line of best fit
    plt.plot(x1, y1, '-r')


    # initiate scary statistics. You don't have to understand this part.
    variance = np.var(y)
    residual = np.var([slope*xx + intercept-yy for xx,yy in zip(x,y)])

    r2 = np.round(1-residual/variance, decimals=2)
    plt.text(.85*max(x), max(y), 'r^2={}'.format(r2))
    plt.text(.85*max(x), .95*max(y), 'y ={}x+{}'.format(round(slope,4), round(intercept,4) ))
    
    plt.show()

if __name__ == "__main__":
    run()