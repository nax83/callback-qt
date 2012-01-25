function App() {
}

App.prototype.clearcache = function(){
    PhoneGap.exec( null, null, "com.phonegap.App", "clearCache", [] );
        }

App.prototype.clearhistory = function(){
    PhoneGap.exec( null, null, "com.phonegap.App", "clearHistory", [] );
        }

App.prototype.exitApp = function(){
    PhoneGap.exec( null, null, "com.phonegap.App", "exitApp", [] );
        }

App.prototype.backhistory = function(){
    PhoneGap.exec( null, null, "com.phonegap.App", "backHistory", [] );
        }

PhoneGap.addConstructor( "com.phonegap.App", function () {
                            navigator.app = new App();

                        } );


