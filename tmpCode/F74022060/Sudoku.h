class Sudoku{
public:
    void ReadIn();
    void Solve();
    void GiveQuestion();
private:
    int mapping[12][12];
    int ansmapping[12][12];
    void BT(int x,int y);
    int flag;
    int superflag;
    int psb[12][12];
    int ckX[10][10];
    int ckY[10][10];
    int aqr[5][5][12];
};
