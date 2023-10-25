from flask import Flask, request, jsonify
import requests

app = Flask(__name__)

event_registry  = list()
pir_state       = 0
button_state    = 0

@app.get('/')
def index():
    response = requests.get('https://api.ipify.org?format=json')
    data     = response.json()
    ip       = data['ip']

    return f'Server ip address {ip}'

@app.route("/pir_status", methods=['GET', 'POST'])
def pir_status():
    global pir_state

    if request.method == 'GET':
        return jsonify({
            'state': pir_state
        }), 200
    else:
        pir_state = request.get_json()['state']
        return '', 200

@app.route("/button_status", methods=['GET', 'POST'])
def button_status():
    global button_state

    if request.method == 'GET':
        return jsonify({
            'state': button_state
        }), 200
    else:
        print(request.data)
        button_state = request.get_json()['state']
        return '', 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=9000)
