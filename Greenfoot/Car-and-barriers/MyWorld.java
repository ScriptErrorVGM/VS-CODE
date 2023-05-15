import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class MyWorld here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class MyWorld extends World
{
    GreenfootSound ambient = new GreenfootSound("ambient.mp3");
    GreenfootSound gameover = new GreenfootSound("game-over.mp3");
    /**
     * Constructor for objects of class MyWorld.
     * 
     */
    public MyWorld()
    {    
        // Create a new world with 600x400 cells with a cell size of 1x1 pixels.
        super(800, 600, 1);
        setBackground("asphalt.jpg");
        create();
        backgroundMusic(); 
    }
    
    public void create() {
        Car car = new Car();
        addObject(car,50,50);
        
        Barrier barrier = new Barrier();
        addObject(barrier,100,150);
        Barrier barrier2 = new Barrier();
        addObject(barrier2,240,150);
        
        Barrier barrier3 = new Barrier();
        addObject(barrier3,270,210);
        Barrier barrier4 = new Barrier();
        addObject(barrier4,160,290);
        
        Barrier barrier5 = new Barrier();
        addObject(barrier5,330,250);
        Barrier barrier6 = new Barrier();
        addObject(barrier6,310,380);
        
        Barrier barrier7 = new Barrier();
        addObject(barrier7,420,230);
        Barrier barrier8 = new Barrier();
        addObject(barrier8,420,360);
        
        Barrier barrier9 = new Barrier();
        addObject(barrier9,500,210);
        Barrier barrier10 = new Barrier();
        addObject(barrier10,500,340);
        
        Barrier barrier11 = new Barrier();
        addObject(barrier11,650,280);
        Barrier barrier12 = new Barrier();
        addObject(barrier12,560,380);
        
        Barrier barrier13 = new Barrier();
        addObject(barrier13,730,440);
        Barrier barrier14 = new Barrier();
        addObject(barrier14,590,440);
    }
    
    public void gameOver() 
    {
        addObject(new GameOver(), getWidth()/2, getHeight()/2);
    }
    
    //GreenfootSound music = new GreenfootSound("BackgroundMusic.mp3");
    public void backgroundMusic() 
    {
        //if(MyWorld.started != true){
            
        if(getObjects(Car.class).size() == 1){
            ambient.playLoop(); 
        }else if (getObjects(Car.class).size() < 1){
            ambient.stop();  
            gameover.playLoop();
        }
    
    }
}
