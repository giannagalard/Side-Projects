import React from 'react'
import { Link } from 'react-router-dom'
import { useState, useEffect } from 'react'


function Debit(props) {
    // set up state
    const [debit, setDebit] = useState([])
    const [description, setDescription] = useState('')
    const [amount, setAmount] = useState(0)


    // fetch data from api 
    async function fetchDebit() {
        await fetch(
            "https://moj-api.herokuapp.com/debits"
        )
            .then((response) => response.json()) // parse response as JSON (can be res.text() for plain response)
            // set the debit data to state with setDebit
            .then((data) => setDebit(data)) // set the data to state
    }

    useEffect(() => { // listen for changes in state, fetch on first render
        fetchDebit()
    }, [])


    // onclick submit button, add debit to current state
    const handleSubmit = () => {
        // make copy of current state
        const Debit = [...debit]
        // add new debit to copy
        Debit.push({ description, amount, date: new Date().toDateString() })
        // update state with new copy
        setDebit(Debit)

        props.updateAccountBalance(amount) // update account balance
    }


    return (
        <div>
            <h1> Debit </h1>
            <h1> Balance = {props.accountBalance} </h1>
            <h1> Add Debit </h1>
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

            {
                debit.map((debit) => {
                    return (
                        <div>
                            <h3> {debit.description} </h3>
                            <p> {debit.amount} </p>
                            <p> {debit.date} </p>
                        </div>
                    )
                })
            }
        </div>
    );
}

export default Debit;