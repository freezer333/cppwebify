var express = require('express');
var app = express();
var bodyParser = require('body-parser');

app.use(express.static('public'));
app.set('view engine', 'jade');

app.use(bodyParser.json()); 
app.use(bodyParser.urlencoded({ extended: true })); 

var types = [
  { 
    title: "standalone_args", 
    description: "Execute C++ executable as a child process, using command line args and stdout.  Based on /cpp/standalone_stdio"
  },
  { 
    title: "standalone_usr", 
    description: "Execute C++ executable as a child process, using direct user input.  Based on /cpp/standalone_usr"
  },
  { 
    title: "ffi", 
    description: "Using Node Foreign Function Interface (ffi) to call C++ code.  Based on /cpp/lib4ffi"
  }, 
  { 
    title: "addon", 
    description: "Creating a Node Addon that can be called like any other module.  Based on /cpp/nodeprime"
  }
  ];


types.forEach(function (type) {
    var route = require('./routes/' + type.title);
    app.use('/'+type.title, route);
});



app.get('/', function (req, res) {
  res.render('index', { routes: types});
});


var server = app.listen(3000, function () {
  var host = server.address().address;
  var port = server.address().port;
  console.log('Web server listing at http://%s:%s', host, port);
});