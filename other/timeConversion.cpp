string timeConversion(string s)
{
    string hour = s.substr(0, 2);
    int hr = stoi(hour);
    string minutes = s.substr(3, 2);
    string seconds = s.substr(6, 2);
    string abbreviations = s.substr(8, 2);
    
    if(hr == 12 && abbreviations == "AM")
    {
        hour = "00";
    }
    else if(hr < 12 && abbreviations == "PM")
    {
        hr = hr + 12;
        hour = to_string(hr);
    }
    
    return hour+":"+minutes+":"+seconds;
}