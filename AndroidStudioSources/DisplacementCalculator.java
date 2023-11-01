package com.example.displacementcalculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    Button buttonGraph;
    Button buttonCalculate;
    Button buttonClear;
    EditText editTextNumberDecimalXi;
    EditText editTextNumberDecimalYi;
    EditText editTextNumberDecimalZi;
    EditText editTextNumberDecimalXf;
    EditText editTextNumberDecimalYf;
    EditText editTextNumberDecimalZf;
    EditText editTextNumberDecimalX;
    EditText editTextNumberDecimalY;
    EditText editTextNumberDecimalZ;
    EditText editTextNumberDecimalDistance;
    EditText editTextTextInGraph;
    EditText editTextTextFiGraph;
    EditText editTextTextDisGraph;

    Double X;
    Double Y;
    Double Z;
    Double Xi;
    Double Yi;
    Double Zi;
    Double Xf;
    Double Yf;
    Double Zf;
    Double mag;
    Double slope;
    String initial_s;
    String final_s;
    String dis_s;
    //URL a = new URL("https://www.desmos.com/calculator");
    //URLConnection Desmos = a.openConnection();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        buttonGraph = (Button) findViewById(R.id.buttonGraph);
        buttonCalculate = (Button) findViewById(R.id.buttonCalculate);
        buttonClear = (Button) findViewById(R.id.buttonClear);
        editTextNumberDecimalXi =  (EditText) findViewById(R.id.editTextNumberDecimalXi);
        editTextNumberDecimalYi =  (EditText) findViewById(R.id.editTextNumberDecimalYi);
        editTextNumberDecimalZi =  (EditText) findViewById(R.id.editTextNumberDecimalZi);
        editTextNumberDecimalXf =  (EditText) findViewById(R.id.editTextNumberDecimalXf);
        editTextNumberDecimalYf =  (EditText) findViewById(R.id.editTextNumberDecimalYf);
        editTextNumberDecimalZf =  (EditText) findViewById(R.id.editTextNumberDecimalZf);
        editTextNumberDecimalX = (EditText) findViewById(R.id.editTextNumberDecimalX);
        editTextNumberDecimalY = (EditText) findViewById(R.id.editTextNumberDecimalY);
        editTextNumberDecimalZ = (EditText) findViewById(R.id.editTextNumberDecimalZ);
        editTextNumberDecimalDistance = (EditText) findViewById(R.id.editTextNumberDecimalDistance);
        editTextTextInGraph = (EditText) findViewById(R.id.editTextTextInGraph);
        editTextTextFiGraph = (EditText) findViewById(R.id.editTextTextFiGraph);
        editTextTextDisGraph = (EditText) findViewById(R.id.editTextTextDisGraph);


        X = 0.0;
        Y = 0.0;
        Z = 0.0;
        Xi = 0.0;
        Yi = 0.0;
        Zi = 0.0;
        Xf = 0.0;
        Yf = 0.0;
        Zf = 0.0;
    }
    public void calculate (View view){
        if(editTextNumberDecimalXi.getText().toString().matches("")){
            Xi = 0.0;
        }
        else{
            Xi = Double.parseDouble(editTextNumberDecimalXi.getText().toString());
        }
       if(editTextNumberDecimalYi.getText().toString().matches("")){
           Yi = 0.0;
       }
       else{
           Yi = Double.parseDouble(editTextNumberDecimalYi.getText().toString());
       }
       if (editTextNumberDecimalZi.getText().toString().matches("")){
           Zi = 0.0;
       }
       else{
           Zi = Double.parseDouble(editTextNumberDecimalZi.getText().toString());
       }
       if(editTextNumberDecimalXf.getText().toString().matches("")){
           Xf = 0.0;
       }
       else{
           Xf = Double.parseDouble(editTextNumberDecimalXf.getText().toString());
       }
       if(editTextNumberDecimalYf.getText().toString().matches("")){
           Yf = 0.0;
       }
       else{
           Yf = Double.parseDouble(editTextNumberDecimalYf.getText().toString());
       }
       if(editTextNumberDecimalZf.getText().toString().matches("")){
           Zf = 0.0;
       }
       else {
           Zf = Double.parseDouble(editTextNumberDecimalZf.getText().toString());
       }
       X = Xf-Xi;
       Y = Yf-Yi;
       Z = Zf-Zi;
       mag = Math.round(Math.sqrt(Math.pow(X,2.0)+Math.pow(Y,2.0)+Math.pow(Z,2.0))*100.0)/100.0;
       editTextNumberDecimalX.setText(X.toString());
       editTextNumberDecimalY.setText(Y.toString());
       editTextNumberDecimalZ.setText(Z.toString());
       editTextNumberDecimalDistance.setText(mag.toString());

    }
    public void graph (View view){
       calculate(view);
       if(Xi<0 && Yi<0){
           initial_s = editTextNumberDecimalYi.getText().toString()+"/"+editTextNumberDecimalXi.getText().toString()+"x{0>x>"+editTextNumberDecimalXi.getText().toString()+"}";
           editTextTextInGraph.setText(initial_s);
       }
       else if(Xi<0 && Yi>0){
           initial_s = editTextNumberDecimalYi.getText().toString()+"/"+editTextNumberDecimalXi.getText().toString()+"x{0>x>"+editTextNumberDecimalXi.getText().toString()+"}";
           editTextTextInGraph.setText(initial_s);
       }
       else if(Xi>0 && Yi<0){
           initial_s = editTextNumberDecimalYi.getText().toString()+"/"+editTextNumberDecimalXi.getText().toString()+"x{0<x<"+editTextNumberDecimalXi.getText().toString()+"}";
           editTextTextInGraph.setText(initial_s);
       }
       else if(Xi>0 && Yi>0){
           initial_s = editTextNumberDecimalYi.getText().toString()+"/"+editTextNumberDecimalXi.getText().toString()+"x{0<x<"+editTextNumberDecimalXi.getText().toString()+"}";
           editTextTextInGraph.setText(initial_s);
       }

        if(Xf<0 && Yf<0){
            final_s = editTextNumberDecimalYf.getText().toString()+"/"+editTextNumberDecimalXf.getText().toString()+"x{0>x>"+editTextNumberDecimalXf.getText().toString()+"}";
            editTextTextFiGraph.setText(final_s);
        }
        else if(Xf<0 && Yf>0){
            final_s = editTextNumberDecimalYf.getText().toString()+"/"+editTextNumberDecimalXf.getText().toString()+"x{0>x>"+editTextNumberDecimalXf.getText().toString()+"}";
            editTextTextFiGraph.setText(final_s);
        }
        else if(Xf>0 && Yf<0){
            final_s = editTextNumberDecimalYf.getText().toString()+"/"+editTextNumberDecimalXf.getText().toString()+"x{0<x<"+editTextNumberDecimalXf.getText().toString()+"}";
            editTextTextFiGraph.setText(final_s);
        }
        else if(Xf>0 && Yf>0) {
            final_s = editTextNumberDecimalYf.getText().toString() + "/" + editTextNumberDecimalXf.getText().toString() + "x{0<x<" + editTextNumberDecimalXf.getText().toString() + "}";
            editTextTextFiGraph.setText(final_s);
        }
        if (X == 0 && Y == 0){
            dis_s = "0.0";
            editTextTextDisGraph.setText(dis_s);
        }
        else if(X<0 && Y<0){
            dis_s = editTextNumberDecimalY.getText().toString()+"/"+editTextNumberDecimalX.getText().toString()+"(x-"+editTextNumberDecimalXi.getText().toString()+")+"+editTextNumberDecimalYi.getText().toString()+"{"+editTextNumberDecimalXi.getText().toString()+">x>"+editTextNumberDecimalXf.getText().toString()+"}";
            editTextTextDisGraph.setText(dis_s);
        }
        else if(X<0 && Y>0){
            dis_s = editTextNumberDecimalY.getText().toString()+"/"+editTextNumberDecimalX.getText().toString()+"(x-"+editTextNumberDecimalXi.getText().toString()+")+"+editTextNumberDecimalYi.getText().toString()+"{"+editTextNumberDecimalXi.getText().toString()+">x>"+editTextNumberDecimalXf.getText().toString()+"}";
            editTextTextDisGraph.setText(dis_s);
        }
        else if(X>0 && Y<0){
            dis_s = editTextNumberDecimalY.getText().toString()+"/"+editTextNumberDecimalX.getText().toString()+"(x-"+editTextNumberDecimalXi.getText().toString()+")+"+editTextNumberDecimalYi.getText().toString()+"{"+editTextNumberDecimalXi.getText().toString()+"<x<"+editTextNumberDecimalXf.getText().toString()+"}";
            editTextTextDisGraph.setText(dis_s);
        }
        else if(X>0 && Y>0) {
            dis_s = editTextNumberDecimalY.getText().toString()+"/"+editTextNumberDecimalX.getText().toString()+"(x-"+editTextNumberDecimalXi.getText().toString()+")+"+editTextNumberDecimalYi.getText().toString()+"{"+editTextNumberDecimalXi.getText().toString()+"<x<"+editTextNumberDecimalXf.getText().toString()+"}";
            editTextTextDisGraph.setText(dis_s);
        }

    }
    public void clearBoard (View view){

        X = 0.0;
        Y = 0.0;
        Z = 0.0;
        Xi = 0.0;
        Yi = 0.0;
        Zi = 0.0;
        Xf = 0.0;
        Yf = 0.0;
        Zf = 0.0;
        mag = 0.0;
        editTextNumberDecimalXi.setText("");
        editTextNumberDecimalXf.setText("");
        editTextNumberDecimalYf.setText("");
        editTextNumberDecimalYi.setText("");
        editTextNumberDecimalZf.setText("");
        editTextNumberDecimalZi.setText("");
        editTextNumberDecimalX.setText("");
        editTextNumberDecimalY.setText("");
        editTextNumberDecimalZ.setText("");
        editTextNumberDecimalDistance.setText("");
        editTextTextDisGraph.setText("");
        editTextTextFiGraph.setText("");
        editTextTextInGraph.setText("");

    }
}