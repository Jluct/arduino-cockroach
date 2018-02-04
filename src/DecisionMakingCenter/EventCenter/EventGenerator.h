#if !defined EventGenerator

class EventGenerator
{
  private:
    int activeIvent[];

  public:
    bool hasActiveEvent = false;
    void setEvent();
    void addAIvent(struct Event);
    void removeEvent(int eventNumber);
};

#endif