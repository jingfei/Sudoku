class Sudoku{
public:
    void ReadIn();
    void Solve();
    void GiveQuestion();
private:
    int mapping[12][12];
    int ansmapping[12][12];
    void BT(int x,int y);
    void ck(int x,int y);
    int flag;
    int superflag;
    int psb[12][12];
    int psb2[12][12][12];
    int aqr[5][5][12];
};
