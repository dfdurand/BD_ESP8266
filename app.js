

var myTimer;

function startTimer(){
 
  myTimer = setInterval(function(){
    fetchDataFromServer();
  }, 1000);
}

function stopTimer(){
  clearInterval(myTimer);
}

function fetchDataFromServer() {
  var url = 'http://192.168.1.33/light/getdata.php';
  $.ajax(url)
    .done(function(data) {
      var obj = JSON.parse(data);
      console.log(obj[0].value);
      var output = 'value: ' + obj[0].value;
        
        document.getElementById('lightvalue').innerHTML = output;
    })

    .fail(function() {
      document.getElementById('lightvalue').innerHTML = 'Error';
    });
}
