 var myRefreshTimeout;

/** Function to refresh the page at specified interval. **/
function startRefresh(refreshPeriod) {
    myRefreshTimeout = setTimeout("window.location.reload();",refreshPeriod);
    window.location.hash = 'start' 
}

/** Function to stop refreshing the page. **/
function stopRefresh() {
    clearTimeout(myRefreshTimeout);
    window.location.hash = 'stop' 
}

function checkForRefresh(refreshPeriod) {
	if (window.location.hash == '#stop') {
    	stopRefresh();
    } else {
    	startRefresh(refreshPeriod);
    }
}
