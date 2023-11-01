package com.example.mytipcalc;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {

    Button buttonPlusTip;
    Button buttonMinusTip;
    Button buttonCalculateTip;
    Button SuggestLowButton;
    Button SuggestMediumButton;
    Button SuggestHighButton;
    EditText editTextNumberDecimalBillAmount;
    EditText editNumberTipPercent;
    EditText editTextNumberDecimalTipAmount;
    EditText editTextNumberDecimalTotalDue;
    Button clearBoard;

    Double billAmount;
    Integer myTipPercent;
    Double tipAmount;
    Double finalAmount;
    EditText editTextRound;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        buttonPlusTip = (Button) findViewById(R.id.PlusPercent);
        buttonMinusTip = (Button) findViewById(R.id.MinusPercent);
        editNumberTipPercent = (EditText) findViewById(R.id.editTextNumber);
        buttonCalculateTip = (Button) findViewById(R.id.buttonCalculate);
        editTextNumberDecimalBillAmount = (EditText) findViewById(R.id.editTextNumberDecimalBillAmount);
        editTextNumberDecimalTipAmount = (EditText) findViewById(R.id.editTextNumberDecimal3);
        editTextNumberDecimalTotalDue = (EditText) findViewById(R.id.editTextNumberDecimalTotalBill);
        SuggestLowButton = (Button) findViewById(R.id.SuggestLowButton);
        SuggestMediumButton = (Button) findViewById(R.id.SuggestMediumButton);
        SuggestHighButton = (Button) findViewById(R.id.SuggestHighButton);
        editTextRound = (EditText) findViewById(R.id.editTextRound);
        clearBoard = (Button) findViewById(R.id.buttonClearBoard);

        billAmount = 0.0;
        myTipPercent = 10;
        tipAmount = 0.0;
        finalAmount = 0.0;
        editNumberTipPercent.setText(myTipPercent.toString() + "%");

    }

    public void increaseTip(View view){
        myTipPercent = myTipPercent + 1;
        if (myTipPercent > 100){
            myTipPercent=100;
        }
        editNumberTipPercent.setText(myTipPercent.toString()+"%");
    }
    public void decreaseTip(View view){
        myTipPercent = myTipPercent - 1;
        if (myTipPercent < 0){
            myTipPercent = 0;
        }
        editNumberTipPercent.setText(myTipPercent.toString()+"%");
    }
    public void calculate(View view){
        if(editTextNumberDecimalBillAmount.getText().toString().matches("")){
            billAmount=0.0;
        }
        else {
            billAmount = Double.parseDouble(editTextNumberDecimalBillAmount.getText().toString());
        }
        billAmount = Math.round(billAmount*100.0)/100.0;
        editTextRound.setText("$"+billAmount.toString());
        tipAmount = billAmount*myTipPercent/100;
        tipAmount = Math.round(tipAmount*100.0)/100.0;
        editTextNumberDecimalTipAmount.setText("$"+tipAmount.toString());
        Double temp;
        temp = 0.0;
        temp = billAmount + tipAmount;
        temp = Math.round(temp*100.0)/100.0;
        editTextNumberDecimalTotalDue.setText("$"+temp.toString());
    }
    public void low(View view){
        editNumberTipPercent.setText("12%");
        myTipPercent=12;
        calculate(view);
    }
    public void medium(View view){
        editNumberTipPercent.setText("15%");
        myTipPercent=15;
        calculate(view);
    }
    public void high(View view){
        editNumberTipPercent.setText("18%");
        myTipPercent=18;
        calculate(view);
    }
    public void clearBoard(View view){
        editNumberTipPercent.setText("10%");
        editTextRound.setText("$0.00");
        editTextNumberDecimalTipAmount.setText("$0.00");
        editTextNumberDecimalTotalDue.setText("$0.00");
        editTextNumberDecimalBillAmount.setText("");
        billAmount=0.0;
        myTipPercent = 10;
        tipAmount = 0.0;
        finalAmount = 0.0;
    }
}