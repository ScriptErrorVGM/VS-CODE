import greenfoot.*;

/**
 * A box with a ball in it.
 * 
 * @author mik
 * @version 1.0
 */
public class Box extends World
{    
    /**
     * Construct the box with a ball in it.
     */
    public Box()
    {    
        super(460, 320, 1);
        setPaintOrder ( Ball.class, Smoke.class ); // paint ball on top
        
        addObject ( new Ball(), getWidth() / 2, getHeight() / 2);
        addObject ( new switchColor(), 50, 50);
        addObject ( new switchColor(), 150, 150);
        addObject ( new switchColor(), 250, 250);
        addObject ( new switchColor(), 10, 50);
        //addObject ( new switchSize(), 100, 100);
        ///addObject ( new switchSpeed(), 150, 150);
    }
}
