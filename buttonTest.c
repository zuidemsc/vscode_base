TEST(read_button,NoPress)
{
    unsigned long button = 1;    

    EXPECT_EQ(button,1);
    EXPECT_EQ(button,2);
}