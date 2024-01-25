class node
{
  public:

         int key;
         node *left, *right;
         node(int key)
         {
            this->key = key;
             left= NULL;
             right= NULL;
        }
};
