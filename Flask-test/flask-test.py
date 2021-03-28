from flask import Flask
app = Flask(__name__)

html="<h1>Gelleo</h1>"

@app.route("/")
def hello():
    return html

if __name__ == "__main__":
    app.run()
