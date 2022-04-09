var fs = require('fs');
(function () {
    class User {
        constructor(id,name) {
            this.id = id;
            this.name = name;
        }
    }

    class Template {
        constructor() {
            this.element = document.querySelector('#app');
            this.newTemplate = this.startTemplate();
        }
        startTemplate() {
            const storage = new Storage();

            if(storage.get('pass') !== '') {
                this.element.innerHTML = ` <div class="people-list">
        <ul class="list">
            <li class="clearfix">
                <div class="about">
                    <div class="name" id="username"></div>
                </div>
            </li>
        </ul>
    </div>
    <div class="chat">
        <div class="chat-header clearfix">
            <div class="chat-about">
                <div class="chat-num-messages">Toplam Mesaj</div>
            </div>
            <i class="fa fa-star"></i>
        </div> 

        <div class="chat-history">
            <ul>
                <li class="clearfix">
                    <div class="message-data align-right">
                        <span class="message-data-name" >Olia</span>
                    </div>
                    <div class="message other-message float-right" id="message-inner">
                    </div>
                </li>
            </ul>
        </div>
        <div class="chat-message clearfix">
            <textarea name="message-to-send" id="message-to-send"
                      placeholder ="Mesaj" rows="3"></textarea>
            <button id="send">Gönder</button>
        </div>
    </div> `;
            } else {
                this.element.innerHTML = `
                <div class="chat-message clearfix">
            <input type="text" name="pass" id="pass-value">
            <button id="pass-send">Gönder</button>
        </div>`;
            }
        }
    }

    class Screen {
        constructor() {
            this.message = document.getElementById('#username');
            this.messageInner = document.getElementById('message-inner');
            this.keypass =document.getElementById('pass-value') ;
        }
    }

    class Storage {
        constructor() {
            this.now =new Date();
        }
        set(name, data, expire = null) {
            const item = {
                value: JSON.stringify(data),
                expire: this.now.getTime() + (parseInt(expire) || 24 * 60 * 5),
            };
            try {
                return window.localStorage.setItem(name, JSON.stringify(item));
            } catch (e) {
                return e;
            }
        }
        get(value) {
            const t = localStorage.getItem(value);
            try {
                return t;
            } catch (e) {
                return e;
            }
        }
    }

    class File {
        constructor() {
            this.filePath =  '../key';
        }

        readFile(url) {
            fs.open(url, 'w', function (err, file) {
                if (err) throw err;
            });
        }
        writeFile(url,data) {
            fs.writeFile(url, data, function (err) {
                if (err) throw err;
            });
        }

        readJson() {
            fs.open(url, 'w', function (err, file) {
                if (err) throw err;
                return JSON.parse(file || '{}') || {};
            });
        }
    }

    class ChatApp {
        constructor() {
            this.button = addEventListener('click',islem);
        }

    }
    const start = new Template();

})();
