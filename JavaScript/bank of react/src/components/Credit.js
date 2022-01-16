import React from 'react'
import { Link } from 'react-router-dom'
import { useState, useEffect } from 'react'

function Credit(props) {
    // set up state
    const [credit, setCredit] = useState([])
    const [description, setDescription] = useState('')
    const [amount, setAmount] = useState(0)

    // fetch data from api
    async function fetchCredit() {
        await fetch(
            "https://moj-api.herokuapp.com/credits"
        )

            // parse response as json (can be res.text() for plain response)
            .then((response) => response.json())
            // set the credit data to state with setCredit
            .then((data) => setCredit(data))

    }

    // listen for changes in state, fetch on first render
    useEffect(() => {
        fetchCredit()
    }, [])

    // submit button on click , add credit to current state
    const handleSubmit = () => {
        // make copy of current state
        const Credit = [...credit]
        // add new credit to copy
        Credit.push({ description, amount, date: new Date().toDateString() })
        // update state with new copy
        setCredit(Credit)
        // update account balance
        props.updateAccountBalance(amount)
    }

    return (
        <div>
            <h1> Credit </h1>
            <h1> Balance = {props.accountBalance} </h1>
            <h1> Add Credit </h1>
            <div>
                <label htmlFor="description"> Description </label>
                <input type="text" name="description" onChange={(e) => setDescription(e.target.value)} value={description} />
            </div>
            <div>
                <label htmlFor="amount"> Amount </label>
                <input type="number" name="amount" onChange={(e) => setAmount(parseInt(e.target.value))} value={amount} />
            </div>
            <button onClick={handleSubmit}>submit</button>
            <Link to="/">Home</Link>
            { // map over credit array 
                credit.map((credit) => {
                    return (
                        <div>
                            <h3> {credit.description} </h3>
                            <p> {credit.amount} </p>
                            <p> {credit.date} </p>
                        </div>
                    )
                })
            }
        </div>
    );
}


export default Credit