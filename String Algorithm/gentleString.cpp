string normalizeString(const string& input)
{
    string result, word;
    stringstream ss(input);
    // Read words, automatically ignoring extra spaces
    while (ss >> word)
    {
        if (!result.empty())
        {
            result += " "; // Add a single space between words
        }
        result += word;
    }
    return result;
}
