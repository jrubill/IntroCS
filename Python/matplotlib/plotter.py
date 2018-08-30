import matplotlib.pyplot as plt 
import numpy as np

def line():
    plt.plot([1,2,3,4])
    plt.ylabel("Numbers")
    plt.show()

def types_of_graphs():
    # A bunch of x values to use
    t = np.arange(0., 5., 0.2)
    '''
    r-- = red dashes
    bs  = blue squares 
    g^  = green arrows
    '''
    #         x y         x  y           x  y
    plt.plot(t, t, 'r--', t, t**2, 'bs', t, t**3, 'g^')
    plt.show()

def pie():
    # col1 = labels, col2 = data
    col1 = list()
    col2 = list()

    with open('data.csv') as f: 
        input = f.readlines()
        for line in input:
            # tokenize each line in file, split on ',
            tokens = line.split(',')
            # this should be our label
            col1.append(tokens[0])
            # this should be or data
            col2.append(tokens[1])

    # MatPlotLib formatting. Check API
    fig1,ax1 = plt.subplots()

    ax1.pie(col2,           # This is our data 
        labels=col1,        # These are our labels
        shadow=True, 
        startangle=90,      # Make it look pretty
        autopct='%1.1f%%'   # Put the percentages on the chart
    )
    
    ax1.axis('equal')       # Helps keep our circle a circle (equal aspect ratio)
    plt.show() 

if __name__ == "__main__":
    pie()