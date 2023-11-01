package edu.highpoint.mymapapplication;

import androidx.fragment.app.FragmentActivity;

import android.os.Bundle;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

import edu.highpoint.mymapapplication.databinding.ActivityMapsBinding;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {

    private GoogleMap mMap;
    private ActivityMapsBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMapsBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
    }

    /**
     * Manipulates the map once available.
     * This callback is triggered when the map is ready to be used.
     * This is where we can add markers or lines, add listeners or move the camera. In this case,
     * we just add a marker near Sydney, Australia.
     * If Google Play services is not installed on the device, the user will be prompted to install
     * it inside the SupportMapFragment. This method will only be triggered once the user has
     * installed Google Play services and returned to the app.
     */
    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;
        // Add a marker in Sydney and move the camera
        LatLng HPU = new LatLng(35.976914921991494, -79.99762285186299);
        mMap.addMarker(new MarkerOptions().position(HPU).title("HPU"));
        LatLng Bojangles = new LatLng(35.98441495778483, -79.97202278762396);
        mMap.addMarker(new MarkerOptions().position(Bojangles).title("Bojangles1"));
        LatLng Bojangles2 = new LatLng(35.99288446974328, -80.02928877293412);
        mMap.addMarker(new MarkerOptions().position(Bojangles2).title("Bojangles2"));
        LatLng Bojangles3 = new LatLng(35.94438678284213, -80.03589981956387);
        mMap.addMarker(new MarkerOptions().position(Bojangles3).title("Bojangles3"));
        mMap.moveCamera(CameraUpdateFactory.newLatLng(HPU));
        //https://developers.google.com/maps/documentation/android-sdk/views onClick
    }
    public void Go(GoogleMap googleMap){
        LatLng Bojangles = new LatLng(35.98441495778483, -79.97202278762396);
        mMap.addMarker(new MarkerOptions().position(Bojangles).title("Bojangles"));
        mMap.moveCamera(CameraUpdateFactory.newLatLng(Bojangles));

    }
}
