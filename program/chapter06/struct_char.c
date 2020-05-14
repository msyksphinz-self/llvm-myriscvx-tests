struct Date
{
  short year;
  char month;
  char day;
  char hour;
  char minute;
  char second;
};

int int_struct()
{
  struct Date date1 = {2012, (char)11, (char)25, (char)9, (char)40, (char)15};
  char m = date1.month;
  char s = date1.second;

  date1.hour = (char)100;

  return 0;
}
