    class NamedPoint
    {
    private:
        float x;
        float y;
        char *name;

    public:
        NamedPoint (float x, float y, char *name)
        {
            this->x    = x;
            this->y    = y;
            if (name == NULL)
                this->name = NULL;
            else
            {
                this->name = new char[strlen(name) + 1];
                strcpy (this->name, name);
            }
        }

        ~NamedPoint ()
        {
            if (name != NULL)
                delete name;             
        }

        NamedPoint (const NamedPoint &copy)
        {
            this->x = copy.x;
            this->y = copy.y;

            if (copy.name != NULL)
            {
                this->name = new char[strlen (copy.name) + 1];
                strcpy (this->name, copy.name);
            }
        }

        NamedPoint& operator=(const NamedPoint& copy)
        {
            this->x = copy.x;
            this->y = copy.y;
            if (this->name != NULL)
                delete this->name;

            if (copy.name != NULL)
            {
                this->name = new char[strlen (copy.name) + 1];
                strcpy (this->name, copy.name);
            }

        }

        float getX()          {return x;}
        float getY()          {return y;}
        const char* getName() {return name;}

        void  setX(float x)       {this->x = x;}
        void  setY(float y)       {this->y = y;}
        void  setName(char* name) {if (this->name != NULL)
                                       delete this->name;
                                   if (name == NULL)
                                       this->name = NULL;
                                   else
                                   {
                                       this->name = new char[strlen(name) + 1];
                                       strcpy (this->name, name);
                                   }}
    };
