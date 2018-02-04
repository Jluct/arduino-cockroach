#if !defined(Platform)

class Platform
{
  protected:
  public:
    void forward();

    void backward();

    /**
     * Только поворот. Направление движения определяются другими методами 
     */
    void rotate(int deg);

    void stop();
};

#endif